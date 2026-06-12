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
- [x] Deleted learning scaffolding: `frontend/triangle.js`, `frontend/cube_coloured.js`.
- [x] Removed the template `WeatherController` and the unused `sphericalToCartesian()` in `earth.js`.
- [x] Fixed `frontend.Dockerfile`: now uses `npm ci` and runs the Vite dev server (was `npm install --production` + `CMD node earth.js`).
- [x] Dropped the obsolete `version` key from `compose-dev.yaml` and tidied its ports/command.
- [x] Added `node_modules/` and `dist/` to `.gitignore` (+ a `frontend/.dockerignore`).

## 4. Configuration & CORS
- [x] Centralized ports/origins in config/env (backend `WorldHopper:AllowedOrigins`, frontend `VITE_BACKEND_URL`); no hardcoded 8080/5173/5206/21248 left in code.
- [x] Removed manual `Access-Control-Allow-*` header juggling in `CameraController`; rely on the CORS policy in `Program.cs`.
- [x] Tightened the `whop frontend` CORS policy to only the origin actually used (the Vite frontend).

## 5. Core features — the hop simulation
- [x] Data pipeline: a .NET console tool (`backend/geocode/`) turns one human-friendly raw file per character (`<name>.places`: nested `live`/`travel` entries with `start .. end` date ranges) into one `date,lat,lon,kind` CSV, geocoding place names via OpenStreetMap Nominatim (no API key) with a git-ignored local cache. End dates are validation-only for now (Option A below).
- [ ] Carry real durations through the pipeline (Option B): use the raw `start .. end` ranges to drive timing — short trips last their actual span and the final `live` extends the timeline — instead of the frontend synthesizing trip duration. Likely extends the CSV schema and the frontend model.
- [x] Discover characters from the CSVs present (n > 0): pair each CSV with the like-named flyer in `static/flyers` (e.g. `bear.csv` ↔ `bear.svg`), probing supported extensions.
- [x] Backend: discover characters from CSV files and serve them with hops at `GET /characters` (schema `date,lat,lon,kind`).
- [x] Load journey data from a configurable, git-ignored location — never bundled or committed (`WorldHopper:DataPath` / env `WorldHopper__DataPath`; Docker volume → `/data`).
- [x] Simulated clock (the whole timeline plays in a configurable ~200s) with play/pause, speed, and prev/next-hop controls; relocates a flyer when time reaches a dated coordinate.
- [x] Long-stay hop (red arrow): relocate a character to a new place and keep it there (animated red great-circle arc; lift scales with distance; flyer rides above the arc, which fades after arrival).
- [x] Short-stay hop (blue arrow): send a character on a temporary trip, then return it (blue great-circle arc; flies out, pauses, flies home; arc fades after return; legs a touch quicker than a long hop).
- [x] Enforce a minimum visible duration for blue hops so brief trips stay legible — the clock slows to a configurable fraction (`blueTimeSlowdown`, default 80% slower) while a short hop is in flight.
- [x] Auto-rotate the globe to centre the active hop, prioritising long (red) arrows; with several of one kind, aim at the geometric mean of their endpoints. Slews smoothly and stays upright (no roll).
- [ ] Centre near-antipodal simultaneous arrows that can't both be shown at once (currently skipped when their endpoints cancel out).
- [x] Render each character's flyer on the globe at its current place (clock-driven long-hop relocation, animated along a red arc).
- [x] Fixed the marker placement: `latLongToVector3` was mirroring east/west (missing the negative `x`); the texture is standard 0°-centered, so no offset is needed.

## 6. Polish & safety nets
- [ ] Add frontend linting/formatting (ESLint + Prettier).
- [ ] Make `vite build` production-ready: runtime-referenced `/static/*` textures aren't bundled — move `static/` under a Vite `publicDir` (dev spin-up already works).
- [ ] Add backend formatting/analyzers (`dotnet format`) plus basic endpoint tests and lat/long math tests.
- [x] Unit-test the geocode preprocessor (parser + validator) with xUnit (`tests/geocode.Tests`); run via Docker.
- [ ] Design pass: lighting, `OrbitControls`, loading states, and a nicer UI for the refresh action.
- [ ] (Optional) Add CI to build both services and run checks on push.
