
#include"zed_ros_driver.h"
int main(int argc, char** argv)
{
  try
  {
    ros::init(argc, argv, "zed_camera");
    arti::ZedCameraROS zed_ros;
    return EXIT_SUCCESS;
  }
  catch (std::runtime_error& e)
  {
    ros::shutdown();
    return EXIT_FAILURE;
  }
}
