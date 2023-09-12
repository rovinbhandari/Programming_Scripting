FROM node:lts-alpine

RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app
RUN chown node:node ./
USER node

COPY package*.json ./
RUN npm ci && npm cache clean --force 
RUN npm install three
RUN npm install --save-dev vite

COPY . /usr/src/app

EXPOSE 8080

CMD ["npx", "vite", "--host"]