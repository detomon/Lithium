Data Types
==========

LIFloat
-------

`typedef float LIFloat`

Basic float type
If makro `LI_USE_DOUBLE` is set to `1` then `double` is used instead of `float`.

Functions
=========

LIAbs
-----

`LIAbs (a)`

Get absolute positive value of `a`
Can be used for any number type since it is a makro

	LIAbs (-4.4) => 4.4


LIMin
-----

`LIMin (a, b)`

Get minimum value of two values `a` and `b`
Can be used for any number type since it is a makro

	LIMin (3.4, -2.7) => -2.7


LIMax
-----

`LIMax (a, b)`

Get maximum value of two values `a` and `b`
Can be used for any number type since it is a makro

	LIMax (3.4, -2.7) => 3.4


LIClamp
-------

`LIClamp (v, l, h)`

Returns `l` if `v` is less than `l` or `h` if `v` is greater than `h`
This is equal to `LIMax (l, LIMin (v, h))`
Can be used for any number type since it is a makro

	LIClamp (0.2, -2.3, 8.7) => -2.3
	LIClamp (6.5, -2.3, 8.7) =>  6.5
	LIClamp (9.5, -2.3, 8.7) =>  8.7


Conversion
==========

LIDegreeToRad
-------------

`LIFloat LIDegreeToRad (LIFloat degree)`

Convert degrees to radians

	LIDegreeToRad (92.4) => 1.612869


LIRadToDegree
-------------

`LIFloat LIRadToDegree (LIFloat rad)`

Convert radians to degrees

	LIRadToDegree (1.612869) => 92.4


