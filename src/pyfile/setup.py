from setuptools import find_packages, setup

package_name = 'pyfile'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yadhu',
    maintainer_email='yadhu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [

            "draw_circle=pyfile.draw_a_circle:main",
            "straight= pyfile.go_straight:main",
            "pose_subscriber=pyfile.pose_subscriber:main",
            "bot_controller=pyfile.bot_control:main",
            "move_robo_server = pyfile.move_robo_server:main",
            "move_robo_client = pyfile.move_robo_client:main"
        ],
    }, 
)
