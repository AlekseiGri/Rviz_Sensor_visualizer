# Rviz_Sensor_visualizer

Простой ROS Noetic-проект на C++, публикующий данные температуры и давления, и отображающий их в RViz.

## 📦 Возможности

- Узел-публикатор (`sensor_publisher`) публикует в темы:
  - `/sensor/temperature` (std_msgs/Float32)
  - `/sensor/pressure` (std_msgs/Float32)
- Узел-визуализатор (`rviz_marker_publisher`) принимает значения из топиков и отображает значения в RViz как текст
- Поддержка запуска через launch-файл
- Добавлен sensor_params.yaml для настройки изменения диапазона температуры, давления и частоты обновления отправки и приема сообщений.

## 🚀 Установка

```bash
cd ~/catkin_ws/src
git clone https://github.com/AlekseiGri/Rviz_Sensor_visualizer.git
cd ..
catkin_make
source ./devel/setup.bash
