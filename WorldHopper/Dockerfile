FROM node:lts-alpine

RUN mkdir -p /app
WORKDIR /app
COPY . /app

RUN npm install
RUN npm install three
RUN npm install --save-dev vite

COPY package*.json ./
COPY . .

EXPOSE 8080

#CMD [ "npm", "run", "start" ]
CMD ["npx", "vite", "--host"]