# WorldHopper — TODO

Roadmap to finish WorldHopper with high-quality, maintainable code and an appealing design.
Ordered by priority; check items off as they land.

## 1. Stabilize dependencies & toolchain (done)
- [x] Backend: moved Docker images off `nightly`/`8.0-preview` to stable `sdk:10.0`/`aspnet:10.0` (.NET 10 LTS), publishing Release.
- [x] Backend: bumped `hop.csproj` to `net10.0`; replaced RC `Microsoft.AspNetCore.OpenApi` with stable `10.0.9`.
- [x] Backend: dropped Swashbuckle for built-in OpenAPI (`AddOpenApi`/`MapOpenApi`) + Scalar UI (`Scalar.AspNetCore` 2.16.3) at `/scalar/v1`.
- [x] Frontend: upgraded `three` 0.156.1 → 0.184.0.
- [x] Frontend: upgraded `vite` 4.4.9 → 8.0.16; regenerated `package-lock.json`.
- [x] Frontend: fixed `package.json` (removed bogus `main`) and added `dev`/`build`/`preview` scripts.
- [x] Pinned Node via `.nvmrc` (24) + `engines`, and pinned `node:24-alpine` in `frontend.Dockerfile`.

## 2. Basic docs
- [x] Add `AGENTS.md` (agent/contributor quick rules).
- [x] Add this `TODO.md` roadmap.
- [x] Write a project `README.md`: the goal, the data pipeline, and how to run it.
- [ ] Document the HTTP API (endpoints, params, responses) — extend `hop.http` with real calls.

## 3. Remove dead code & tech debt
- [ ] Delete learning scaffolding: `frontend/triangle.js`, `frontend/cube_coloured.js`.
- [ ] Remove the template `WeatherController` and the unused `sphericalToCartesian()` in `earth.js`.
- [x] Fixed `frontend.Dockerfile`: now uses `npm ci` and runs the Vite dev server (was `npm install --production` + `CMD node earth.js`).
- [x] Dropped the obsolete `version` key from `compose-dev.yaml` and tidied its ports/command.
- [x] Added `node_modules/` and `dist/` to `.gitignore` (+ a `frontend/.dockerignore`).

## 4. Configuration & CORS
- [ ] Centralize ports/origins via env vars or config; remove hardcoded 8080/5173/5206/21248.
- [ ] Remove manual `Access-Control-Allow-*` header juggling in `CameraController`; rely on the CORS policy in `Program.cs`.
- [ ] Tighten the `whop frontend` CORS policy to only the origins actually used.

## 5. Core features — the hop simulation
- [ ] Data pipeline: turn the human-friendly raw file (place names + dates) into one `coordinates + dates` CSV per character via a geocoding step.
- [ ] Discover characters from the CSVs present (n > 0): pair each CSV with the like-named flyer in `static/flyers` (e.g. `bear.csv` ↔ `bear.svg`).
- [ ] Load journey data from a configurable, git-ignored location — never bundled or committed.
- [ ] Simulated clock that advances time and triggers a hop when it reaches a dated coordinate.
- [ ] Long-stay hop (red arrow): relocate a character to a new place and keep it there.
- [ ] Short-stay hop (blue arrow): send a character on a temporary trip, then return it.
- [ ] Enforce a minimum visible duration for blue hops so brief trips stay legible.
- [ ] Render each character's flyer on the globe at its current place.
- [ ] Fix the marker bug: point misplaced because the Earth texture isn't centered at 0° longitude — add the offset.

## 6. Polish & safety nets
- [ ] Add frontend linting/formatting (ESLint + Prettier).
- [ ] Make `vite build` production-ready: runtime-referenced `/static/*` textures aren't bundled — move `static/` under a Vite `publicDir` (dev spin-up already works).
- [ ] Add backend formatting/analyzers (`dotnet format`) plus basic endpoint tests and lat/long math tests.
- [ ] Design pass: lighting, `OrbitControls`, loading states, and a nicer UI for the refresh action.
- [ ] (Optional) Add CI to build both services and run checks on push.
