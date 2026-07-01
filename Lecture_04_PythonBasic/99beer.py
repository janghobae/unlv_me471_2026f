for bottles in range(99, 1, -1):

    print(str(bottles), 'bottles of beer on the wall,')
    print(str(bottles), 'bottles of beer.')
    print('Take one down and pass it around,')

    if bottles - 1 == 1:
        print('1 bottle of beer on the wall.\n')
    else:
        print(str(bottles - 1), 'bottles of beer on the wall.\n')

print('1 bottle of beer on the wall,')
print('1 bottle of beer.')
print('Take one down and pass it around,')
print('No more bottles of beer on the wall.\n')

print('No more bottles of beer on the wall,')
print('no more bottles of beer.')
print('Go to the store and buy some more,')
print('99 bottles of beer on the wall.')