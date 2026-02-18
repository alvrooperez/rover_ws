from setuptools import find_packages
from setuptools import setup

setup(
    name='osr_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('osr_interfaces', 'osr_interfaces.*')),
)
