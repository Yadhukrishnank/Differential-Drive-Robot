#!/bin/bash

set -e

# Source the ROS 2 setup
source /opt/ros/humble/setup.bash

# Source the installed workspace setup
source /workspace/install/setup.bash

# Execute the command passed as argument to the script
exec "$@"
