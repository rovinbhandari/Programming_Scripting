FROM node:24-alpine

WORKDIR /usr/src/app

# Install dependencies first to leverage Docker layer caching.
COPY package.json package-lock.json ./
RUN npm ci

COPY . .

EXPOSE 5173

# Vite dev server; --host exposes it outside the container.
CMD ["npm", "run", "dev", "--", "--host"]