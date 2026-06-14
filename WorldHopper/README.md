# WorldHopper

> Watch a cast of characters — a **bear**, a **rain cloud**, or any you add — hop around a 3D globe, retracing real journeys driven by date-stamped coordinates.

WorldHopper replays the travels of one or more characters over a textured 3D Earth. A simulated clock advances through time, and whenever it reaches a dated location in a character's itinerary, that character *hops* to the new place.

## The travellers
- Any number of characters (**n > 0**) can hop — each is a **flyer** icon in `frontend/static/flyers/` (the shipped examples are a bear and a rain cloud).
- A character is defined by a CSV of dated coordinates whose **file name matches its flyer** (e.g. `bear.csv` ↔ `bear.svg`). Add more CSVs to add more travellers.
- Each CSV is that character's itinerary: a time-ordered list of places and dates.

## Two kinds of hop
- **Long-stay hop — red arrow.** A relocation: the character flies to a new place and *lives* there. Triggered when the simulated date reaches the next dated coordinate in that character's data. A *temporary relocation* (a `live` nested under another `live`) is a red hop out and a red hop back once the stay ends.
- **Short-stay hop — blue arrow.** A temporary trip: the character travels away from its current home and then returns. Connected or nested travels (back-to-back trips, or sub-trips that branch off and return) flow into one multi-stop blue tour — home → A → B → home — instead of separate out-and-back hops. Same date-driven trigger.
- Short stays can be tiny next to the long-stay timeline, so **blue hops are given a minimum on-screen duration** to stay visible — this prolonging is deliberate.

## Data pipeline
Journey data is prepared in three steps:
1. **Raw input (human-friendly):** one `<name>.places` file per character — nested `live` / `travel` entries with `start .. end` date ranges (format documented in `backend/geocode/`).
2. **Geocode → CSVs:** the `geocode` tool resolves place names to coordinates via OpenStreetMap Nominatim (no API key; results cached locally) and emits one `date,lat,lon,kind,via` CSV per character, each named after its flyer. The optional `via` field carries a tour's extra stops as `lat lon;lat lon;…`; single-stop hops leave it empty. Run: `docker compose -f compose-dev.yaml run --rm geocode`.
3. **Visualise:** the app reads every character CSV it finds and animates the hops.

> ⚠️ **Privacy — read before adding data.** Real place names, dates, and coordinates (raw input *and* generated CSVs) are **never** committed to git. They are read only from a **configurable location** outside the repository. See `AGENTS.md`.

## Architecture
- `frontend/` — Vite + Three.js globe; entry `earth.js`, served via `index.html`.
- `backend/hop/` — ASP.NET Core (.NET 10) API; serves character itineraries from CSVs at `/characters`.
- `backend/geocode/` — .NET console tool that turns raw `.places` files into the character CSVs (the geocoding step).
- `tests/` — xUnit tests (`tests/geocode.Tests` covers the geocode parser + validator).
- `compose-dev.yaml` — builds and runs both services together for local dev.

## Run it
```sh
docker compose -f compose-dev.yaml up --build
```
- Frontend: http://localhost:5173
- Backend API docs (Scalar): http://localhost:8080/scalar/v1
- Point `WORLDHOPPER_DATA_PATH` at your git-ignored CSV folder (defaults to `./.worldhopper-data`).
- Changing ports? Set `VITE_BACKEND_URL` (browser → API base URL) and `WorldHopper__AllowedOrigins` (comma-separated CORS origins); the defaults work as-is.
- Generate CSVs from raw `.places` files: `docker compose -f compose-dev.yaml run --rm geocode`.
- Run the tests: `docker compose -f compose-dev.yaml run --rm tests`.

## Status
Work in progress. **Done:** a rotating globe; the `/characters` API; flyers rendered on the globe; a simulated clock with play/pause, speed, and prev/next-hop controls; red long-stay arcs and blue short-stay round trips; clock slowdown that keeps brief trips visible; auto-centring on the active hop; and the geocoding data pipeline with tests. **Next:** polish — linting, a production build, a design pass, and the remaining items in `TODO.md`.
