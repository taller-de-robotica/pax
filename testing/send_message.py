import requests
import argparse

def send_message(ip, port, message):
    # Construct the URL using the IP address and port
    url = f"http://{ip}:{port}/command/"  # Replace '/your-endpoint' with the correct API endpoint
    
    # Define the message data to send
    #data = {'message': message}
    data = message
    
    # Send a POST request
    try:
        response = requests.post(url, data=data)
        
        # Check the response status
        if response.status_code == 200:
            print("Message sent successfully!")
            print("Response:", response)
        else:
            print(f"Failed to send message. Status code: {response.status_code}")
    except requests.exceptions.RequestException as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Send a message via HTTP POST to a specified IP and port.")
    
    # Add arguments
    parser.add_argument("ip", type=str, help="The IP address of the target")
    parser.add_argument("port", type=str, help="The port to use")
    parser.add_argument("message", type=str, help="The message to send")

    # Parse the arguments
    args = parser.parse_args()

    # Call the function with parsed arguments
    send_message(args.ip, args.port, args.message)

