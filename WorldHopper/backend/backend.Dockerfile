# Use the official .NET 7 SDK image as the base image
FROM mcr.microsoft.com/dotnet/nightly/sdk:8.0-preview AS build

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Restore the project dependencies
RUN dotnet restore

# Build the project and generate the output files
RUN dotnet publish -c Release -o out

# Use the official .NET 7 runtime image as the base image
FROM mcr.microsoft.com/dotnet/nightly/runtime:8.0-preview AS runtime

# Set the working directory to /app
WORKDIR /app

# Copy the output files from the build stage into the runtime image
COPY --from=build /app/out ./

EXPOSE 5206

# Start the application
ENTRYPOINT ["dotnet", "hop.dll"]