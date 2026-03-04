# generated from rosidl_generator_py/resource/_idl.py.em
# with input from osr_interfaces:msg/CommandCorner.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CommandCorner(type):
    """Metaclass of message 'CommandCorner'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('osr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'osr_interfaces.msg.CommandCorner')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__command_corner
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__command_corner
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__command_corner
            cls._TYPE_SUPPORT = module.type_support_msg__msg__command_corner
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__command_corner

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CommandCorner(metaclass=Metaclass_CommandCorner):
    """Message class 'CommandCorner'."""

    __slots__ = [
        '_left_front_pos',
        '_left_back_pos',
        '_right_front_pos',
        '_right_back_pos',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'left_front_pos': 'double',
        'left_back_pos': 'double',
        'right_front_pos': 'double',
        'right_back_pos': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.left_front_pos = kwargs.get('left_front_pos', float())
        self.left_back_pos = kwargs.get('left_back_pos', float())
        self.right_front_pos = kwargs.get('right_front_pos', float())
        self.right_back_pos = kwargs.get('right_back_pos', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.left_front_pos != other.left_front_pos:
            return False
        if self.left_back_pos != other.left_back_pos:
            return False
        if self.right_front_pos != other.right_front_pos:
            return False
        if self.right_back_pos != other.right_back_pos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def left_front_pos(self):
        """Message field 'left_front_pos'."""
        return self._left_front_pos

    @left_front_pos.setter
    def left_front_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'left_front_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_front_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_front_pos = value

    @builtins.property
    def left_back_pos(self):
        """Message field 'left_back_pos'."""
        return self._left_back_pos

    @left_back_pos.setter
    def left_back_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'left_back_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_back_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_back_pos = value

    @builtins.property
    def right_front_pos(self):
        """Message field 'right_front_pos'."""
        return self._right_front_pos

    @right_front_pos.setter
    def right_front_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'right_front_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_front_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_front_pos = value

    @builtins.property
    def right_back_pos(self):
        """Message field 'right_back_pos'."""
        return self._right_back_pos

    @right_back_pos.setter
    def right_back_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'right_back_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_back_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_back_pos = value
