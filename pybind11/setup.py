#!/usr/bin/env python3
# encoding: utf-8
from setuptools import setup, Extension
import pybind11

example_module = Extension(
    'example',
    sources=['example-classy.cpp'],
    language='C++',
    include_dirs=[pybind11.get_include(True)], )

setup(name='example', version='0.1.0', description='example module written in C++', ext_modules=[example_module])
