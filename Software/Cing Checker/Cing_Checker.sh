#!/bin/bash
fuser -k 5000/tcp
gunicorn --bind 127.0.0.1:5000 flask_app:app
