def p():return 1
'''
    123
'''
def main():
    '''
        123
    '''
    x = "def p():return 1\n'''\n    123\n'''\ndef main():\n    '''\n        123\n    '''\n    x = %r\n    print(x %% x)\nmain()"
    print(x % x)
main()
