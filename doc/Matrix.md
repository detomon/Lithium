Data Types
==========

LIMat2
------

	typedef struct {
	   LIFloat m00, m01;
	   LIFloat m10, m11;
	} LIMat2


2×2-component matrix

LIMat3
------

	typedef struct {
	   LIFloat m00, m01, m02;
	   LIFloat m10, m11, m12;
	   LIFloat m20, m21, m22;
	} LIMat3


3×3-component matrix

LIMat4
------

	typedef struct {
	   LIFloat m00, m01, m02, m03;
	   LIFloat m10, m11, m12, m13;
	   LIFloat m20, m21, m22, m23;
	   LIFloat m30, m31, m32, m33;
	} LIMat4


4×4-component matrix

Creation
========

LIMakeIdentityMat2
------------------

`void LIMakeIdentityMat2 (LIMat2 * m)`

Initialize 2×2-component matrix `m` with identity matrix

LIMakeIdentityMat3
------------------

`void LIMakeIdentityMat3 (LIMat3 * m)`

Initialize 3×3-component matrix `m` with identity matrix

LIMakeIdentityMat4
------------------

`void LIMakeIdentityMat4 (LIMat4 * m)`

Initialize 4×4-component matrix `m` with identity matrix

LIMakeTranslationMat3
---------------------

`void LIMakeTranslationMat3 (LIMat3 * m, LIVec2 v)`

Initialize matrix `m` with identity matrix and set translation components (`M20 … M21`) to vector `v`

LIMakeTranslationMat4
---------------------

`void LIMakeTranslationMat4 (LIMat4 * m, LIVec3 v)`

Initialize matrix `m` with identity matrix and set translation components (`M30 … M32`) to vector `v`

LIMakeScaleMat2
---------------

`void LIMakeScaleMat2 (LIMat2 * m, LIVec2 v)`

Initialize matrix `m` with identity matrix and set scale components (`M00 … M11`) to vector `v`

LIMakeScaleMat3
---------------

`void LIMakeScaleMat3 (LIMat3 * m, LIVec2 v)`

Initialize matrix `m` with identity matrix and set scale components (`M00 … M11`) to vector `v`

LIMakeScaleMat3Vec3
-------------------

`void LIMakeScaleMat3Vec3 (LIMat3 * m, LIVec3 v)`

Initialize matrix `m` with identity matrix and set scale components (`M00 … M22`) to vector `v`

LIMakeScaleMat4
---------------

`void LIMakeScaleMat4 (LIMat4 * m, LIVec3 v)`

Initialize matrix `m` with identity matrix and set scale components (`M00 … M22`) to vector `v`

LIMakeRotationMat2
------------------

`void LIMakeRotationMat2 (LIMat2 * m, LIFloat a)`

Initialize matrix `m` with identity matrix and set rotation components (`M00 … M11`)
to rotation by `a` degrees counter clockwise

LIMakeRotationMat3
------------------

`void LIMakeRotationMat3 (LIMat3 * m, LIFloat a)`

Initialize matrix `m` with identity matrix and set rotation components (`M00 … M11`)
to rotation by `a` degrees counter clockwise

LIMakeRotationMat3Vec3
----------------------

`void LIMakeRotationMat3Vec3 (LIMat3 * m, LIVec3 v, LIFloat a)`

Initialize matrix `m` with identity matrix and set rotation components (`M00 … M22`)
to rotation around axis `v` by `a` degrees counter clockwise

LIMakeRotationMat4
------------------

`void LIMakeRotationMat4 (LIMat4 * m, LIVec3 v, LIFloat a)`

Initialize matrix `m` with identity matrix and set rotation components (`M00 … M22`)
to rotation around axis `v` by `a` degrees counter clockwise

Transformation
==============

LITranslateMat3
---------------

`void LITranslateMat3 (LIMat3 * m, LIVec2 v)`

Apply translation by adding vector `v` to translation components (`M20 … M21`)
Vector `v` is first multiplied by rotation components (`M00 … M11`)	before added so the translation occurs in the matrix coordinate space

LITranslateMat4
---------------

`void LITranslateMat4 (LIMat4 * m, LIVec3 v)`

Apply translation by adding vector `v` to translation components (`M30 … M32`)
Vector `v` is first multiplied by rotation components (`M00 … M22`)	before added so the translation occurs in the matrix coordinate space

LIScaleMat2
-----------

`void LIScaleMat2 (LIMat2 * m, LIVec2 v)`

Apply scaling by multipling rotation component (`M00 … M11`) by vector `v`

LIScaleMat3
-----------

`void LIScaleMat3 (LIMat3 * m, LIVec2 v)`

Apply scaling by multipling rotation component (`M00 … M11`) by vector `v`

LIScaleMat3Vec3
---------------

`void LIScaleMat3Vec3 (LIMat3 * m, LIVec3 v)`

Apply scaling by multipling rotation component (`M00 … M22`) by vector `v`

LIScaleMat4
-----------

`void LIScaleMat4 (LIMat4 * m, LIVec3 v)`

Apply scaling by multipling rotation component (`M00 … M22`) by vector `v`

LIRotateMat2
------------

`void LIRotateMat2 (LIMat2 * m, LIFloat a)`

Apply rotation to rotation component (`M00 … M11`) by `a` degrees counter clockwise

LIRotateMat3
------------

`void LIRotateMat3 (LIMat3 * m, LIFloat a)`

Apply rotation to rotation component (`M00 … M11`) by `a` degrees counter clockwise

LIRotateMat3Vec3
----------------

`void LIRotateMat3Vec3 (LIMat3 * m, LIVec3 v, LIFloat a)`

Apply rotation to rotation component (`M00 … M22`) around axis `v` by `a` degrees counter clockwise

LIRotateMat4
------------

`void LIRotateMat4 (LIMat4 * m, LIVec3 v, LIFloat a)`

Apply rotation to rotation component (`M00 … M22`) around axis `v` by `a` degrees counter clockwise

Multiplication
==============

LIMultMat2
----------

`void LIMultMat2 (LIMat2 * r, const LIMat2 * m, const LIMat2 * n)`

Multiply matrix `m` by matrix `n` and write result to `r`
Target pointer `r` may be the same as `m` or `n`

LIMultMat3
----------

`void LIMultMat3 (LIMat3 * r, const LIMat3 * m, const LIMat3 * n)`

Multiply matrix `m` by matrix `n` and write result to `r`
Target pointer `r` may be the same as `m` or `n`

LIMultMat3Mat2
--------------

`void LIMultMat3Mat2 (LIMat3 * r, const LIMat3 * m, const LIMat2 * n)`

Multiply rotation components (`M00 … M11`) of matrix `m` by matrix `n` and write result to `r`
Target pointer `r` may be the same as `m`

LIMultMat4
----------

`void LIMultMat4 (LIMat4 * r, const LIMat4 * m, const LIMat4 * n)`

Multiply matrix `m` by matrix `n` and write result to `r`
Target pointer `r` may be the same as `m` or `n`

LIMultMat4Mat3
--------------

`void LIMultMat4Mat3 (LIMat4 * r, const LIMat4 * m, const LIMat3 * n)`

Multiply rotation components (`M00 … M22`) of matrix `m` by matrix `n` and write result to `r`
Target pointer `r` may be the same as `m`

LIMultMat2Vec2
--------------

`LIVec2 LIMultMat2Vec2 (LIMat2 * m, LIVec2 v)`

Multiply matrix `m` by vector `v` and return result vector

LIMultMat3Vec2
--------------

`LIVec2 LIMultMat3Vec2 (LIMat3 * m, LIVec2 v)`

Multiply rotation components (`M00 … M11`) of matrix `m` by vector `v` and return result vector

LIMultMat3Vec3
--------------

`LIVec3 LIMultMat3Vec3 (LIMat3 * m, LIVec3 v)`

Multiply matrix `m` by vector `v` and return result vector

LIMultMat4Vec3
--------------

`LIVec3 LIMultMat4Vec3 (LIMat4 * m, LIVec3 v)`

Multiply rotation components (`M00 … M22`) of matrix `m` by vector `v` and return result vector

Inverse, Transpose
==================

LIInvertMat2
------------

`bool LIInvertMat2 (LIMat2 * r, const LIMat2 * m)`

Invert matrix `m` and write result to `r`
Target pointer `r` may be the same as `m`
If matrix is not invertible `false` is returned

LIInvertMat3
------------

`bool LIInvertMat3 (LIMat3 * r, const LIMat3 * m)`

Invert matrix `m` and write result to `r`
Target pointer `r` may be the same as `m`
If matrix is not invertible `false` is returned

LIInvertMat4
------------

`bool LIInvertMat4 (LIMat4 * r, const LIMat4 * m)`

Invert matrix `m` and write result to `r`
Target pointer `r` may be the same as `m`
If matrix is not invertible `false` is returned

LITransposeMat2
---------------

`void LITransposeMat2 (LIMat2 * r, const LIMat2 * m)`

Transpose matrix `m` and write result to `r`
Target pointer `r` may be the same as `m`

	0.974370 -0.224951  =>  0.974370  0.224951
	0.224951  0.974370     -0.224951  0.974370


LITransposeMat3
---------------

`void LITransposeMat3 (LIMat3 * r, const LIMat3 * m)`

Transpose matrix `m` and write result to `r`
Target pointer `r` may be the same as `m`

	 0.870180 -0.429840  0.240884      0.870180  0.450611 -0.199341
	 0.450611  0.891989 -0.036117  => -0.429840  0.891989  0.139973
	-0.199341  0.139973  0.969882      0.240884 -0.036117  0.969882


LITransposeMat4
---------------

`void LITransposeMat4 (LIMat4 * r, const LIMat4 * m)`

Transpose matrix `m` and write result to `r`
Target pointer `r` may be the same as `m`

	 0.870180 -0.429840  0.240884  0.000000      0.870180  0.450611 -0.199341  0.000000
	 0.450611  0.891989 -0.036117  0.000000  => -0.429840  0.891989  0.139973  0.000000
	-0.199341  0.139973  0.969882  0.000000      0.240884 -0.036117  0.969882  0.000000
	 0.000000  0.000000  0.000000  1.000000      0.000000  0.000000  0.000000  1.000000


Camera
======

LIMakeModelviewEyeMat4
----------------------

`void LIMakeModelviewEyeMat4 (LIMat4 * m, LIVec3 eye, LIVec3 lookAt, LIVec3 up)`

...

LIMakeProjectionOrthogonalMat4
------------------------------

`void LIMakeProjectionOrthogonalMat4 (LIMat4 * m, LIFloat width, LIFloat height, LIFloat near, LIFloat far)`

...

LIMakeProjectionPerspectiveMat4
-------------------------------

`void LIMakeProjectionPerspectiveMat4 (LIMat4 * m, LIFloat width, LIFloat height, LIFloat near, LIFloat far, LIFloat fovy)`

…

Copying
=======

LICopyMat2
----------

`void LICopyMat2 (LIMat2 * n, const LIMat2 * m)`

Copy matrix `m` to matrix `n`

LICopyMat2Mat3
--------------

`void LICopyMat2Mat3 (LIMat2 * n, const LIMat3 * m)`

Copy rotation and scaling components (`M00 … M11`) of matrix `m` to matrix `n`

LICopyMat3
----------

`void LICopyMat3 (LIMat3 * n, const LIMat3 * m)`

Copy matrix `m` to matrix `n`

LICopyMat3Mat2
--------------

`void LICopyMat3Mat2 (LIMat3 * n, const LIMat2 * m)`

Copy matrix `m` to rotation and scaling components (`M00 … M11`) of matrix `n`

LICopyMat3Mat4
--------------

`void LICopyMat3Mat4 (LIMat3 * n, const LIMat4 * m)`

Copy rotation and scaling components (`M00 … M22`) of matrix `m` to matrix `n`

LICopyMat4
----------

`void LICopyMat4 (LIMat4 * n, const LIMat4 * m)`

Copy matrix `m` to matrix `n`

LICopyMat4Mat3
--------------

`void LICopyMat4Mat3 (LIMat4 * n, const LIMat3 * m)`

Copy matrix `m` to rotation and scaling components (`M00 … M22`) of matrix `n`

Debug
=====

LIPrintMat2
-----------

`void LIPrintMat2 (const LIMat2 * m)`

Print components of matrix `m`

	0.707107 -0.707107
	0.707107  0.707107


LIPrintMat3
-----------

`void LIPrintMat3 (const LIMat3 * m)`

Print components of matrix `m`

	0.707107 -0.707107  0.000000
	0.707107  0.707107  0.000000
	0.000000  0.000000  1.000000


LIPrintMat4
-----------

`void LIPrintMat4 (const LIMat4 * m)`

Print components of matrix `m`

	 0.728028  0.608789  0.315202  0.000000
	-0.525105  0.790791 -0.314508  0.000000
	-0.440727  0.063457  0.895395  0.000000
	 0.000000  0.000000  0.000000  1.000000


