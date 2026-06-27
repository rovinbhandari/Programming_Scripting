Let's set up AGENTS.md (50 sentences hard cap) and a README.md (100 sentences hard cap). Also set up TODO (empty) and docs/ with an architectural overview file (described below).

This project is about a new project called 'pandex', which stands for pan-index. The idea in a nutshell is about creating an index of all (data) files spread across various PCs, VMs, online storages etc. 

We will spend quite some time discussing and iterating over the architecture, requirements, validation sets, tools, language choices (inclined towards Rust), LLM choices (for keyword extraction, embeddings, search and RAG) etc. before implementing it. We will also keep things minimal, functionally correct at all times, and modular. 

In that spirit, you MUST:
1. Ask not assume when there are multiple choices or in doubt. 
2. Key choices made should be documented in the architecture (edit/substract and not always add; everything is versioned).
3. Architectural overview doc and diagram should be understandble at a glance, with links to detailed concepts/notes.
4. Favour less code and pluggable/modular functionality.
5. 1 commit = 1 holistic feature or significant bugfix. Small accompanying changes should be mentioned in commit messages.
6. Verify build, test and rubber-duck validation of work before calling it a day (or committing).
7. README/TODO should be updated when key project details change or work is on the backburner.
8. Never commit real data files (test data is ok). 
9. When modifying code, look holistically if something can be removed/refactored to reduce overall code/complexity.
10. We will obsess over quality and performance. This project has to run on a wide variety of devices, different OSes, utilise device-usage troughs, keep data/schema versioned, async processing of scanned files (for embeddings, keyword extraction), surgical re-scans if needed etc. We will use telemetry and benchmarks to make sure we document performance and then revisit the slow parts. 
11. Keep things fun; our mascot is an omniscient Red Panda! 
12. Use opportunities to teach me concepts, suggest alternative approaches, pose some trivia. 

Let's set up the files above and start adding things to a PLAN.md too.
