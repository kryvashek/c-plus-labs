# c-plus-labs
C++ labs 2018

## Code rules

Code rules are next:
1. Name format of local variables: `someValueName`.
1. Name format of private fields: `_somePrivateFieldName`.
1. Name format of private methods: `somePrivateMethodName`.
4. Name format for public fields: `SomePublicFieldName`.
3. Name format for public methods: `SomePublicMethodName`.
5. Code formatting example:
```c++
for( int i = 0; i < 10; i++ ) {
	MyClass exemplar;

	if( someConditionFunction( arg1, arg2 ) )
		for( int j = i; j < 10; j++ )
			exemplar.Method( arg3, arg4 );
}
```