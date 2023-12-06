from venmo_api import Client

def request_pay(amount: float, message: str, username: str, access_token: str):
    client = Client(access_token)
    user = client.user.get_user_by_username(username)
    if user != None:
        client.payment.request_money(amount, message, user.id)
        return True
    print("Failed to find user")
    return False