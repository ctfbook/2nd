FROM python:3

ADD ./app /opt/app
RUN useradd -s /usr/sbin/nologin ctf &&\
	pip install -r /opt/app/requirements.txt

USER ctf

CMD ["python", "/opt/app/app.py"]
EXPOSE 5000