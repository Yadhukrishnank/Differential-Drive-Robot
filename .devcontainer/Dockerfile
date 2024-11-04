FROM osrf/ros:humble-desktop-full
ARG USERNAME=USERNAME
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Delete user if it exists in container (e.g., Ubuntu Noble: ubuntu)
RUN if id -u $USER_UID ; then userdel `id -un $USER_UID` ; fi

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Install ROS and teleop-related packages
RUN apt-get update && apt-get install -y \
    python3-pip \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-rviz2 \
    ros-humble-xacro \
    ros-humble-twist-mux \
    ros-humble-nav2-bringup \
    ros-humble-slam-toolbox \
    ros-humble-teleop-twist-keyboard \
    ros-humble-joint-state-publisher-gui \
    ros-humble-robot-state-publisher \  
    ros-humble-rqt-common-plugins \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-gazebo-ros2-control \
    ros-humble-image-transport \
    ros-humble-camera-info-manager \
    ros-humble-laser-filters \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

ENV SHELL /bin/bash
RUN echo "source /opt/ros/humble/setup.bash" >> /home/$USERNAME/.bashrc
# Set the default user
USER $USERNAME
CMD ["/bin/bash"]