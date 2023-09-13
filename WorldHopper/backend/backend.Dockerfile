# Use the official .NET 7 SDK image as the base image
FROM mcr.microsoft.com/dotnet/nightly/sdk:8.0-preview AS hopbuild

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Restore the project dependencies
RUN dotnet restore hop/hop.csproj

# Build the project and generate the output files
RUN dotnet publish hop/hop.csproj -c Debug -o out

# Use the official .NET 7 runtime image as the base image
FROM mcr.microsoft.com/dotnet/nightly/aspnet:8.0-preview AS hopruntime

# Set the working directory to /app
WORKDIR /app

# Copy the output files from the build stage into the runtime image
COPY --from=hopbuild /app/out ./

EXPOSE 5206 8080

# Start the application
ENTRYPOINT ["dotnet", "hop.dll"]