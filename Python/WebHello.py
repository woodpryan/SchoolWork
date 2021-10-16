from flask import Flask
# Initialize the app
app = Flask(__name__)
# Define a "route" to the hello world function
@app.route('/')
def helloWorld () :
    return 'Hello World'
# Run the app on http :// localhost :8085
app.run(debug=True, port = 8085)
