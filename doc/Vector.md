Data Types
==========

LIVec2
------

	typedef struct {
	   LIFloat x;
	   LIFloat y;
	} LIVec2


2-component vector

LIVec3
------

	typedef struct {
	   LIFloat x;
	   LIFloat y;
	   LIFloat z;
	} LIVec3


3-component vector

LIVec4
------

	typedef struct {
	   LIFloat x;
	   LIFloat y;
	   LIFloat z;
	   LIFloat w;
	} LIVec4


4-component vector

Creation
========

LIMakeVec2
----------

`LIVec2 LIMakeVec2 (LIFloat x, LIFloat y)`

Initializer for 2-component vector

	LIVec2 a = LIMakeVec2 (2.3, -0.8);


LIMakeVec3
----------

`LIVec3 LIMakeVec3 (LIFloat x, LIFloat y, LIFloat z)`

Initializer for 3-component vector

	LIVec3 a = LIMakeVec3 (2.3, -0.8, 0.2);


LIMakeVec4
----------

`LIVec4 LIMakeVec4 (LIFloat x, LIFloat y, LIFloat z, LIFloat w)`

Initializer for 4-component vector

	LIVec4 a = LIMakeVec4 (0.6, 0.3, 0.8, 0.1);


Arithmetic
==========

LIAddVec2
---------

`LIVec2 LIAddVec2 (LIVec2 a, LIVec2 b)`

Add vectors `a` and `b`

	LIAddVec2 (
	   LIMakeVec2 (-3.1, 5.7),
	   LIMakeVec2 (1.0, 4.5)
	) => (-2.1, 10.2)


LIAddVec3
---------

`LIVec3 LIAddVec3 (LIVec3 a, LIVec3 b)`

Add vectors `a` and `b`

	LIAddVec3 (
	   LIMakeVec3 (-3.1, 5.7, 0.6),
	   LIMakeVec3 (1.0, 4.5, -0.2)
	) => (-2.1, 10.2, 0.4)


LIAddVec4
---------

`LIVec4 LIAddVec4 (LIVec4 a, LIVec4 b)`

Add vectors `a` and `b`

	LIAddVec4 (
	   LIMakeVec4 (-3.1, 5.7, 0.6, -7.6),
	   LIMakeVec4 (1.0, 4.5, -0.2, 9.2)
	) => (-2.1, 10.2, 0.4, 1.6)


LISubVec2
---------

`LIVec2 LISubVec2 (LIVec2 a, LIVec2 b)`

Subtract vector `b` from `a`

	LISubVec2 (
	   LIMakeVec2 (-3.1, 5.7),
	   LIMakeVec2 (1.0, 4.5)
	) => (-4.1, 1.2)


LISubVec3
---------

`LIVec3 LISubVec3 (LIVec3 a, LIVec3 b)`

Subtract vector `b` from `a`

	LISubVec3 (
	   LIMakeVec3 (-3.1, 5.7, 0.6),
	   LIMakeVec3 (1.0, 4.5, -0.2)
	) => (-4.1, 1.2, 0.8)


LISubVec4
---------

`LIVec4 LISubVec4 (LIVec4 a, LIVec4 b)`

Subtract vector `b` from `a`

	LISubVec4 (
	   LIMakeVec4 (-3.1, 5.7, 0.6, -7.6),
	   LIMakeVec4 (1.0, 4.5, -0.2, 9.2)
	) => (-4.1, 1.2, 0.8, -16.8)


LIMultVec2
----------

`LIVec2 LIMultVec2 (LIVec2 a, LIFloat l)`

Multiply vector `a` by `l`

	LIMultVec2 (
	   LIMakeVec2 (-3.1, 5.7),
	   0.4
	) => (-1.24, 2.28)


LIMultVec3
----------

`LIVec3 LIMultVec3 (LIVec3 a, LIFloat l)`

Multiply vector `a` by `l`

	LIMultVec3 (
	   LIMakeVec3 (-3.1, 5.7, 0.6),
	   0.4
	) => (-1.24, 2.28, 0.24)


LIMultVec4
----------

`LIVec4 LIMultVec4 (LIVec4 a, LIFloat l)`

Multiply vector `a` by `l`

	LIMultVec4 (
	   LIMakeVec4 (-3.1, 5.7, 0.6, -7.6),
	   0.4
	) => (-1.24, 2.28, 0.24, -3.04)


Other
=====

LILengthVec2
------------

`LIFloat LILengthVec2 (LIVec2 v)`

Get length of vector `v`

	LILengthVec2 (LIMakeVec2 (3.0, 4.0)) => 5.0


LILengthVec3
------------

`LIFloat LILengthVec3 (LIVec3 v)`

Get length of vector `v`

	LILengthVec3 (LIMakeVec3 (3.0, 4.0, 5.0)) => 7.071068.0


LIDistanceVec2
--------------

`LIFloat LIDistanceVec2 (LIVec2 a, LIVec2 b)`

Get distance between vectors `a` and `b`
This is equal to: `LILengthVec2 (LISubVec2 (a, b))`

	LIDistanceVec2 (
	   LIMakeVec2 (-3.1, 5.7),
	   LIMakeVec2 (1.0, 4.5)
	) => 4.272002


LIDistanceVec3
--------------

`LIFloat LIDistanceVec3 (LIVec3 a, LIVec3 b)`

Get distance between vectors `a` and `b`
This is equal to: `LILengthVec3 (LISubVec3 (a, b))`

	LIDistanceVec3 (
	   LIMakeVec3 (-3.1, 5.7, 0.6),
	   LIMakeVec3 (1.0, 4.5, -0.2)
	) => 4.346263


LINormalizeVec2
---------------

`LIVec2 LINormalizeVec2 (LIVec2 v)`

Returns vector with same direction as vector `v` but with length `1.0`

	LINormalizeVec2 (-3.1, 5.7) => (-0.477772, 0.878484)


LINormalizeVec3
---------------

`LIVec3 LINormalizeVec3 (LIVec3 v)`

Returns vector with same direction as vector `v` but with length `1.0`

	LINormalizeVec3 (-3.1, 5.7, 0.6) => (-0.475742, 0.874752, 0.092079)


LIDotVec2
---------

`LIFloat LIDotVec2 (LIVec2 a, LIVec2 b)`

Get dot product of vectors `a` and `b`

	LIDotVec2 (
	   LIDotVec2 (-0.477772, 0.878484),
	   LIDotVec2 (-0.216930, 0.976187)
	) => 0.961208


LIDotVec3
---------

`LIFloat LIDotVec3 (LIVec3 a, LIVec3 b)`

Get dot product of vectors `a` and `b`

	LIDotVec3 (
	   LIMakeVec3 (-0.475742, 0.874752,  0.092079),
	   LIMakeVec3 (-0.216726, 0.975270, -0.043345)
	) => 0.952233


LICrossVec3
-----------

`LIVec3 LICrossVec3 (LIVec3 a, LIVec3 b)`

Get cross product of vectors `a` and `b`

	LICrossVec3 (
	   LIMakeVec3 (-0.475742, 0.874752,  0.092079),
	   LIMakeVec3 (-0.216726, 0.975270, -0.043345)
	) => (-0.127718, -0.040577, -0.274395)


LIReflectVec2
-------------

`LIVec2 LIReflectVec2 (LIVec2 vector, LIVec2 wall)`

Get result vector by reflecting `vector` at `wall`
`wall` is a vector pointing away from the wall (has not to be normalized)

LIReflectVec3
-------------

`LIVec3 LIReflectVec3 (LIVec3 vector, LIVec3 wall)`

Get result vector by reflecting `vector` at `wall`
`wall` is a vector pointing away from the wall (has not to be normalized)

Rotation
========

LIRotateVec2
------------

`LIVec2 LIRotateVec2 (LIVec2 vector, LIFloat angle)`

Rotate `vector` around origin point `(0, 0)` by `angle` degrees counter clockwise

LIRotateRelativeVec2
--------------------

`LIVec2 LIRotateRelativeVec2 (LIVec2 vector, LIFloat angle, LIVec2 center)`

Rotate `vector` around `center` point by `angle` degrees counter clockwise

LIRotateVec3
------------

`LIVec3 LIRotateVec3 (LIVec3 vector, LIVec3 axis, LIFloat angle)`

Rotate `vector` around origin point `(0, 0, 0)` by `angle` degrees counter clockwise

LIRotateRelativeVec3
--------------------

`LIRotateRelativeVec3 (LIVec3 vector, LIVec3 axis, LIFloat angle, LIVec3 center)`

Rotate `vector` around `center` point by `angle` degrees counter clockwise

Debug
=====

LIPrintVec2
-----------

`void LIPrintVec2 (LIVec2 v)`

Print components of vector `v`

	-3.540000  15.573453


LIPrintVec3
-----------

`void LIPrintVec3 (LIVec3 v)`

Print components of vector `v`

	-3.540000  15.573453  -0.000134


LIPrintVec4
-----------

`void LIPrintVec4 (LIVec4 v)`

Print components of vector `v`

	-3.540000  15.573453  -0.000134  0.500000


