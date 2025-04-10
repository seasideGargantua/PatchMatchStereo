from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools
import pybind11

class get_pybind_include(object):
    """Helper class to determine the pybind11 include path"""

    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        return pybind11.get_include(self.user)

ext_modules = [
    Extension(
        'PatchMatchStereo',  # Module name
        ['PatchMatchStereo/ext.cpp'],  # Source file
        include_dirs=[
            # Path to pybind11 headers
            get_pybind_include(),
            get_pybind_include(user=True)
        ],
        language='c++'
    ),
]

setup(
    name='PatchMatchStereo',
    version='0.1',
    author='Your Name',
    author_email='yangqinglin@zju.edu.cn',
    description='A Python wrapper for PatchMatchStereo using pybind11',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.5.0'],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)