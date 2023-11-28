# zed_ros_driver
This is a driver for zed camera which send ros massage.

just for fun. a toy .
zed_ros_driver
===========
A simple zed camera driver which only use opencv and ros.

# Usage:
1. git the packge into your working space

    ```
    cd catkin_ws/src
    git clone https://github.com/atomtn/zed_ros_driver.git
    cd ..
    catkin_make
    ```
2. Get your calibration files:
    You can get your calibration files from zed or do a calibration your self by using ROS camera calibration package.

    (1). From zed:

    Find your zed calibration files in
    ```
    cd /usr/local/zed/settings
    ```
    or download from:
    http://calib.stereolabs.com/?SN=XXXX

    Note: XXXX is your last four digit S/N of your camera, make sure to change it!!

    put the .conf file into zed_ros_driver/config folder

    update launch file configuration file name in zed_ros_driver.launch into your SNXXXX.conf
    ```
    roscd zed_ros_driver/launch
    gedit zed_ros_driver.launch
    ```
    change XXXX into the .conf file you have, for example 1010
    ```
    <arg name="config_file_location" default="$(find zed_ros_driver)/config/SN1010.conf"/>
    ```

    (2). Do a calibration yourself:

    This option is suggested. Reference: http://wiki.ros.org/camera_calibration
    ```
    roslaunch zed_ros_driver camera_calibration.launch
    ```
    After calibration:
    Find the left.yaml and right.yaml in the tar file and put them into the zed_ros_driver/config folder.
    The calibration file will be loaded if you turn <load_zed_config> off in the launch file.

3. launch the code
    ```
    roslaunch zed_ros_driver zed_ros_driver.launch
    ```
## Launch file parameters

 Parameter                    |           Description                                       |              Value
------------------------------|-------------------------------------------------------------|-------------------------
 device_name                  | camera device_name                                          | sting
 resolution                   | ZED Camera resolution                                       | '0': HD2K
 _                            | _                                                           | '1': HD1080
 _                            | _                                                           | '2': HD720
 _                            | _                                                           | '3': VGA
 frame_rate                   | Rate at which images are published                          | int
 left_frame_id                | Left Frame ID                                               | string
 right_frame_id               | Right Frame ID                                              | string
 load_zed_config              | Whether to use ZED calibration file                         | bool
 config_file_location         | The location of ZED calibration file                        | string
 show_image                   | Whether to use opencv show image                            | bool
 encoding                     | image encoding                                              | string


# Author:
  whu.s
