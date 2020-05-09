import sys

def main():
    checks_passed = True
    if(checks_passed):
        print("some_ci_script : checks passed!")
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
