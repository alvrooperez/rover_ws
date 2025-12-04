from setuptools import find_packages, setup
import os
from glob import glob
from setuptools import setup

package_name = 'mi_controlador'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        
        # --- AÑADE ESTA LÍNEA ---
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='alvaro',
    maintainer_email='alvaro@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            #'test_saludo = mi_controlador.mi_primer_nodo:main',
            'motor = mi_controlador.control_motor:main',
            'escucha = mi_controlador.receptor:main',
            'teleop = mi_controlador.teleop:main',
        ],
    },
)
