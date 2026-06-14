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
- [x] Data pipeline: a .NET console tool (`backend/geocode/`) turns one human-friendly raw file per character (`<name>.places`: nested `live`/`travel` entries with `start .. end` date ranges) into one `date,lat,lon,kind,via` CSV, geocoding place names via OpenStreetMap Nominatim (no API key) with a git-ignored local cache. End dates are validation-only for now (Option A below).
- [ ] Carry real durations through the pipeline (Option B): use the raw `start .. end` ranges to drive timing — short trips last their actual span and the final `live` extends the timeline — instead of the frontend synthesizing trip duration. Likely extends the CSV schema and the frontend model.
- [x] Support a nested `live` under a `live` (temporary relocation): the character moves to a second home for a while and then returns — unlike a `travel`, they actually live there. Indentation is now significant; the model (`Live`/`Travel` in `Itinerary.cs`), parser, and validator represent a live-within-a-live (nested range must sit inside the parent's), projected as a red hop out and a red hop back (date-contiguous siblings chain).
- [x] Support connected travels — a `travel` nested under another `travel`, or two `travel`s at the same indent with one immediately following the other: one trip flows straight into the next without returning home between them (home → A → B → home) instead of independent out-and-back blue hops. Each maximal date-contiguous run projects to one short hop carrying its extra stops in the CSV `via` field; the frontend animates it as a single multi-leg blue tour (sub-trips branch off and return to their base).
- [x] Discover characters from the CSVs present (n > 0): pair each CSV with the like-named flyer in `static/flyers` (e.g. `bear.csv` ↔ `bear.svg`), probing supported extensions.
- [x] Backend: discover characters from CSV files and serve them with hops at `GET /characters` (schema `date,lat,lon,kind,via`; `via` waypoints carried as a `Via` list on each hop).
- [x] Load journey data from a configurable, git-ignored location — never bundled or committed (`WorldHopper:DataPath` / env `WorldHopper__DataPath`; Docker volume → `/data`).
- [x] Simulated clock (the whole timeline plays in a configurable ~200s) with play/pause, speed, and prev/next-hop controls; relocates a flyer when time reaches a dated coordinate.
- [x] Long-stay hop (red arrow): relocate a character to a new place and keep it there (animated red great-circle arc; lift scales with distance; flyer rides above the arc, which fades after arrival).
- [x] Short-stay hop (blue arrow): send a character on a temporary trip, then return it (blue great-circle arc; flies out, pauses, flies home; arc fades after return; legs a touch quicker than a long hop).
- [x] Enforce a minimum visible duration for blue hops so brief trips stay legible — the clock slows to a configurable fraction (`blueTimeSlowdown`, default 80% slower) while a short hop is in flight.
- [x] Auto-rotate the globe to centre the active hop, prioritising long (red) arrows; with several of one kind, aim at the geometric mean of their endpoints. Slews smoothly and stays upright (no roll).
- [ ] Centre near-antipodal simultaneous arrows that can't both be shown at once (currently skipped when their endpoints cancel out).
- [ ] Smooth the fan-in/out of coincident flyers: travellers currently pop between stacked (shared place) and fanned-out positions when they converge or diverge — ease the transition.
- [ ] Constrain the globe's auto-rotation to Earth's natural eastward spin — never reverse direction to re-centre; only modulate speed.
- [ ] Look ahead to each flyer's next hop and pre-rotate: ease the spin faster/slower so the destination is already framed when the flyer departs, smoothing the motion.
- [ ] Keep flyers in focus by tilting the spin axis to maximise their screen time — at rest and mid-hop — rather than yaw-centring alone.
- [ ] Finetune short hops: keep close pairs (a few hundred km apart) legible via a θ-driven blend (θ = acos(â·b̂) as the single driver) — feed each hop's real arc lift into `fitCameraDistance` so small bulges dolly closer, with a lowered `cameraMinDistance`; scale the arrow shaft/head by `cameraDistance/rest` (clamped) for a steady on-screen head; raise the short-hop lift floor. Agreed feel: moderate zoom + modest arrow up-scaling, keep some surrounding map context.
- [x] Render each character's flyer on the globe at its current place (clock-driven long-hop relocation, animated along a red arc).
- [x] Fixed the marker placement: `latLongToVector3` was mirroring east/west (missing the negative `x`); the texture is standard 0°-centered, so no offset is needed.

## 6. Polish & safety nets
- [ ] Add frontend linting/formatting (ESLint + Prettier).
- [ ] Make `vite build` production-ready: runtime-referenced `/static/*` textures aren't bundled — move `static/` under a Vite `publicDir` (dev spin-up already works).
- [ ] Add backend formatting/analyzers (`dotnet format`) plus basic endpoint tests and lat/long math tests.
- [x] Unit-test the geocode preprocessor (parser + validator) with xUnit (`tests/geocode.Tests`); run via Docker.
- [ ] (Optional) Add CI to build both services and run checks on push.

## 7. Design pass
- [ ] Lighting and material polish for the globe (atmosphere/specular, nicer day texture).
- [ ] Add `OrbitControls` for user-driven rotate/zoom, coexisting with auto-centring.
- [ ] Loading states for the globe, flyers, and data; a friendlier control for the refresh/spin action.
