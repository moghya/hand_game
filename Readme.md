## Build Docker image:
- `docker build . -t rps_game`

## Create container to run the built binary:
- `docker run -it rps_game`

## Run the game
- `./rps_game`

## Rebuild and re-run rps_game
If any changes are done in source code withing the container.
Rebuild and re-run using following commands.
- `cmake .`
- `make my_http_log_monitor_tester`
- `./rps_game`
