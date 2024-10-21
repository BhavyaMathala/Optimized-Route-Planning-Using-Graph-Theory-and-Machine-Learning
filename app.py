from flask import Flask, jsonify
from traffic_prediction import predict_traffic

app = Flask(__name__)

@app.route('/predict/<string:location>', methods=['GET'])
def predict(location):
    prediction = predict_traffic(location)
    return jsonify(prediction)

if __name__ == '__main__':
    app.run(debug=True)
