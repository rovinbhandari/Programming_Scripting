FROM node:lts-alpine

ENV NODE_ENV=production

WORKDIR /usr/src/app
RUN chown -R node /usr/src/app

COPY ["package.json", "package-lock.json*", "npm-shrinkwrap.json*", "./"]
RUN npm install --production --silent && mv node_modules ../

COPY . .

USER node

EXPOSE 5173

CMD ["node", "earth.js"]
#CMD ["npx", "vite", "--host"]