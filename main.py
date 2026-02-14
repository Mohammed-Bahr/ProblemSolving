def my_decorator (func):
    def wrapper ():
        print("starting" + func.__name__)
        func()
        print("Complete !")

    return wrapper

@my_decorator
def  do_this():
    print("do this function")


@my_decorator
def do_that ():
    print("do that function.")


do_that()
do_that()