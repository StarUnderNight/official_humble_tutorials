/**
 * Clion 加载项目后会首先使用ros_ws/build目录下的 more_interfaces，但这样会找不到build_ws/install/下的 more_interfaces
 * 因此直接点击 main函数前面的运行，就会自己编译目标，然后找到 build_ws/install下的头文件
 */
#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_interfaces/msg/address_book.hpp"

using namespace std::chrono_literals;

class AddressBookPublisher : public rclcpp::Node
{
public:
    AddressBookPublisher()
            : Node("address_book_publisher")
    {
        address_book_publisher_ =
                this->create_publisher<more_interfaces::msg::AddressBook>("address_book", 10);

        auto publish_msg = [this]() -> void {
            auto message = more_interfaces::msg::AddressBook();

            message.first_name = "John";
            message.last_name = "Doe";
            message.phone_number = "1234567890";
            message.phone_type = message.PHONE_TYPE_MOBILE;

            std::cout << "Publishing Contact\nFirst:" << message.first_name <<
                      "  Last:" << message.last_name << std::endl;

            this->address_book_publisher_->publish(message);
        };
        timer_ = this->create_wall_timer(1s, publish_msg);
    }

private:
    rclcpp::Publisher<more_interfaces::msg::AddressBook>::SharedPtr address_book_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AddressBookPublisher>());
    rclcpp::shutdown();

    return 0;
}