# Build stage: stable .NET 10 SDK
FROM mcr.microsoft.com/dotnet/sdk:10.0 AS geocodebuild

WORKDIR /app

# Restore as a separate layer for better caching.
COPY geocode/geocode.csproj geocode/
RUN dotnet restore geocode/geocode.csproj

# Copy the rest of the source and publish a Release build.
COPY . .
RUN dotnet publish geocode/geocode.csproj -c Release -o out

# Runtime stage: stable .NET 10 runtime (console tool — no ASP.NET needed)
FROM mcr.microsoft.com/dotnet/runtime:10.0 AS geocoderuntime

WORKDIR /app
COPY --from=geocodebuild /app/out ./

ENTRYPOINT ["dotnet", "geocode.dll"]
