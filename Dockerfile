# Use the official ROS 2 image
FROM osrf/ros:humble-desktop-full

# Set the working directory
WORKDIR /workspace

# Install necessary packages for ROS and GUI
RUN apt-get update && \
    apt-get install -y \
    python3-colcon-common-extensions \
    ros-humble-gazebo-ros \
    ros-humble-gazebo-dev \
    ros-humble-rviz2 \
    libxcb-xinerama0 \
    libxkbcommon-x11-0 \
    libxrender1 \
    libxcb1 \
    libgl1-mesa-glx \
    libgl1-mesa-dri \
    && rm -rf /var/lib/apt/lists/*

# Copy your ROS 2 packages into the container
COPY src/my_robot_description /workspace/my_robot_description
COPY src/my_robot_bringup /workspace/my_robot_bringup
COPY pyfile /workspace/pyfile

# Build the ROS 2 workspace
RUN /bin/bash -c "source /opt/ros/humble/setup.bash && colcon build"

# Copy the entrypoint script
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Set the entrypoint script that sources ROS 2 and maintains the environment
ENTRYPOINT [ "/entrypoint.sh" ]

# Default command (bash)
CMD ["bash"]
