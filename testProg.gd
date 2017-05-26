a = 1;
b = 2;
if ( a < b )
{
print a;
}
else
{
print b;
};

a = 3;
repeat ( 3 + 2 ) 
{
print 0;
if ( a < 5 )
{
a  = 5;
};
};
print a;

a = 6;
b = 2;
if ( a < b )
{
print a;
}
else
{
print b;
if ( b < 3 )
{
b = b + a;
}
print b;
};
