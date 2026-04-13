from setuptools import setup

package_name = 'brazo_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'pyserial'],
    zip_safe=True,
    maintainer='muarcianos',
    maintainer_email='tu@email.com',
    description='Control de servos y stepper para el brazo del rover',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'mi_brazo_node = brazo_control.mi_brazo_node:main',
            'brazo_node = brazo_control.brazo_base_node:main',
            'checkpoint_brazo = brazo_control.brazo_checkpoint:main'
        ],
    },
)
