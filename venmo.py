from venmo_api import Client

def login():
    user = input("Enter Venmo Username")
    password = input("Enter Venmo Password")
    access_token = Client.get_access_token(username=user, password=password)
    print("My token: ", access_token)
    return access_token

def logout(access_token : str = ""):
    if access_token == "":
        access_token = input("Input access token\n")
    client = Client(access_token=access_token)
    client.log_out(access_token)

def request_pay(amount: float, message: str, username: str, access_token: str = ""):
    if access_token != "":
        client = Client(access_token)
    else:
        client = Client(login)
    user = client.user.get_user_by_username(username)
    if user != None:
        client.payment.request_money(amount, message, user.id)
        if access_token != "":
            logout(access_token)
        return True
    print("Failed to find user")
    if access_token != "":
        logout(access_token)
    return False