WorldHopper is a 3D globe app: `frontend/` is Vite + vanilla JS + Three.js (entry `earth.js`); `backend/hop/` is an ASP.NET Core Web API; `compose-dev.yaml` runs both.
Prioritize high-quality, minimal & maintainable code and appealing design over speed; work in slow, reflective iterations, not fast partial fixes.

## Layout
- `frontend/` — Vite app; entry `earth.js`, served via `index.html`; assets in `static/`.
- `backend/hop/` — ASP.NET Core Web API (controllers: Camera, Characters).
- `backend/geocode/` — .NET console tool: raw `.places` files → character CSVs (geocoding step).
- `tests/` — xUnit tests (`tests/geocode.Tests`).
- `compose-dev.yaml` — builds and runs both services for local dev.
- Git root is the parent `Programming_Scripting` monorepo; only touch `WorldHopper/` here.

## Commands
- Run everything: `docker compose -f compose-dev.yaml up --build`.
- Frontend dev: `cd frontend && npm install && npx vite --host` (http://localhost:5173).
- Backend: local .NET 10 SDK available — `dotnet build`/`dotnet run` directly, or build/run via Docker.
- Generate CSVs from raw `.places`: `docker compose -f compose-dev.yaml run --rm geocode`.
- Run tests: `dotnet test tests/geocode.Tests` (local, fast), or `docker compose -f compose-dev.yaml run --rm tests`.
- Endpoints are configurable: `VITE_BACKEND_URL` (frontend → API) and `WorldHopper__AllowedOrigins` (backend CORS, comma-separated); defaults 5173/8080.

## Conventions
- Frontend: ES modules, 4-space indent, `camelCase`; keep Three.js setup declarative and small.
- Backend: C# with nullable + implicit usings on; one controller per route group; `PascalCase`.
- Prefer stable releases — never depend on preview/nightly/RC versions.
- Centralize ports/origins in config or env vars; do not hardcode them in code.
- Reference assets with absolute `/static/...` paths.
- Docs/Markdown: one logical line per paragraph or bullet — no manual line wrapping.

## Quality bar
- When requirements are unclear, ask a clarifying question instead of assuming.
- Favor less code: delete dead/scaffolding code instead of working around it.
- Make small, focused commits with clear messages (match the existing terse style).
- Verify the affected service builds and runs end to end before calling work done.
- Update `README`/`TODO.md` when setup or behavior changes.
- Never commit secrets, `node_modules/`, `dist/`, or `bin/`/`obj/`.
- Never commit real place names, dates, or coordinates (raw input or generated CSVs); load journey data only from a configurable, git-ignored location.
