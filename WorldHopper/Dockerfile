FROM node:lts-alpine

RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app
RUN chown node:node ./
USER node

COPY . /usr/src/app
COPY package*.json ./
#COPY . .

RUN npm ci && npm cache clean --force 
COPY . .

RUN npm install three
RUN npm install --save-dev vite

EXPOSE 8080

#CMD [ "npm", "run", "start" ]
CMD ["npx", "vite", "--host"]