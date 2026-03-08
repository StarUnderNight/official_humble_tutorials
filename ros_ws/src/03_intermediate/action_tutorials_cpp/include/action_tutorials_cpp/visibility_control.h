/**
 * @file visibility_control.h
 * @brief 该头文件用于控制库中符号的可见性，是跨平台(DLL/共享库)开发的标准实践
 *
 * 核心作用：
 * 1. 控制哪些函数/类可以被外部调用（导出），哪些仅内部可见（隐藏）
 * 2. 解决Windows和Linux/macOS平台下动态库符号导出/导入的兼容性问题
 * 3. 避免符号污染，提升编译链接效率，减小库文件体积
 */

// 防止头文件重复包含的保护宏
// 命名规则：PROJECT_NAME__FILENAME_H_ (大写，路径分隔符替换为下划线)
#ifndef ACTION_TUTORIALS_CPP__VISIBILITY_CONTROL_H_
#define ACTION_TUTORIALS_CPP__VISIBILITY_CONTROL_H_

/*
 * extern "C" 只能修饰函数、函数指针、全局变量
 * extern "C" 的核心是关闭 C++ 的名字修饰(name mangling)，改用 C 语言的编译规则
 * 主要解决：C++编译的库被C语言调用时的链接错误，或C库被C++调用的兼容性问题
 * 注意：这里包裹宏定义不会影响宏的作用，只是确保宏展开后的符号遵循C链接规则
 */

// 检测是否是C++编译器编译
#ifdef __cplusplus
extern "C"
{
#endif

  // 这段逻辑借鉴自GCC维基的示例：https://gcc.gnu.org/wiki/Visibility
  // 核心目标：为不同编译器/操作系统提供统一的符号可见性宏定义

  // ====================== Windows/Cygwin 平台处理 ======================
  // 检测是否是Windows系统(_WIN32)或Cygwin环境(__CYGWIN__)
#if defined _WIN32 || defined __CYGWIN__

  // 如果是GNU编译器(GCC/MinGW)
#ifdef __GNUC__
  // 定义导出宏：告诉编译器将符号导出到DLL中
  #define ACTION_TUTORIALS_CPP_EXPORT __attribute__ ((dllexport))
  // 定义导入宏：告诉编译器从DLL中导入符号
  #define ACTION_TUTORIALS_CPP_IMPORT __attribute__ ((dllimport))
#else
  // 非GNU编译器(如MSVC)，使用Windows原生的__declspec关键字
  #define ACTION_TUTORIALS_CPP_EXPORT __declspec(dllexport)
  #define ACTION_TUTORIALS_CPP_IMPORT __declspec(dllimport)
#endif

  // 检测是否正在编译DLL本身(ACTION_TUTORIALS_CPP_BUILDING_DLL宏由构建系统定义)
#ifdef ACTION_TUTORIALS_CPP_BUILDING_DLL
  // 编译DLL时：使用导出宏，让符号对外可见
  #define ACTION_TUTORIALS_CPP_PUBLIC ACTION_TUTORIALS_CPP_EXPORT
#else
  // 使用DLL时：使用导入宏，从DLL中导入符号
  #define ACTION_TUTORIALS_CPP_PUBLIC ACTION_TUTORIALS_CPP_IMPORT
#endif

  // 为类型定义公开可见性（Windows平台下和普通PUBLIC宏一致）
  #define ACTION_TUTORIALS_CPP_PUBLIC_TYPE ACTION_TUTORIALS_CPP_PUBLIC
  // Windows平台下LOCAL宏无需特殊处理（默认就是内部可见）
  #define ACTION_TUTORIALS_CPP_LOCAL

  // ====================== 类Unix平台处理(Linux/macOS等) ======================
#else
  // 类Unix平台使用GCC的visibility属性控制符号可见性
  // 导出宏：设置符号可见性为默认（对外可见）
  #define ACTION_TUTORIALS_CPP_EXPORT __attribute__ ((visibility("default")))
  // 类Unix平台无需显式导入，所以导入宏为空
  #define ACTION_TUTORIALS_CPP_IMPORT

  // 检测GCC版本是否>=4（4.0以上支持visibility属性）
  #if __GNUC__ >= 4
    // 公开可见：符号对外可见，可被库的使用者调用
    #define ACTION_TUTORIALS_CPP_PUBLIC __attribute__ ((visibility("default")))
    // 本地可见：符号仅库内部可见，外部无法访问（避免符号污染）
    #define ACTION_TUTORIALS_CPP_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    // 低版本GCC不支持visibility，使用空定义（符号默认全部公开）
    #define ACTION_TUTORIALS_CPP_PUBLIC
    #define ACTION_TUTORIALS_CPP_LOCAL
  #endif

  // 类Unix平台下类型可见性无需特殊定义
  #define ACTION_TUTORIALS_CPP_PUBLIC_TYPE

#endif

// 结束extern "C"块
#ifdef __cplusplus
}
#endif

// 结束头文件保护宏
#endif  // ACTION_TUTORIALS_CPP__VISIBILITY_CONTROL_H_