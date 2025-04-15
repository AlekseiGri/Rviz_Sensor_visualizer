# Rviz_Sensor_visualizer

Простой ROS Noetic-проект на C++, публикующий данные температуры и давления, и отображающий их в RViz.
A simple ROS Noetic project in C++ that publishes temperature and pressure data and visualizes them in RViz.

## 📦 Возможности (Features)

- Узел-публикатор (`sensor_publisher`) публикует в темы:
  - `/sensor/temperature` (std_msgs/Float32)
  - `/sensor/pressure` (std_msgs/Float32)
- Узел-визуализатор (`rviz_marker_publisher`) принимает значения из топиков и отображает значения в RViz как текст
- Поддержка запуска через launch-файл
- Добавлен sensor_params.yaml для настройки изменения диапазона температуры, давления и частоты обновления отправки и приема сообщений.

-A publisher node (sensor_publisher) publishes to the following topics:
/sensor/temperature (std_msgs/Float32)
/sensor/pressure (std_msgs/Float32)

-A visualization node (rviz_marker_publisher) subscribes to these topics and displays the values in RViz as text markers

-Supports launching via a launch file

-Includes a sensor_params.yaml file for configuring temperature/pressure ranges and message update frequency

## 🚀 Установка (Installation)

```bash
cd ~/catkin_ws/src
git clone https://github.com/AlekseiGri/Rviz_Sensor_visualizer.git
cd ..
catkin_make
source ./devel/setup.bash
