#!/bin/bash
fuser -k 8000/tcp
gunicorn flask_app:app
