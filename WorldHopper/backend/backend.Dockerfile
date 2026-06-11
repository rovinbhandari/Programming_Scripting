# Build stage: stable .NET 10 SDK
FROM mcr.microsoft.com/dotnet/sdk:10.0 AS hopbuild

WORKDIR /app

# Restore as a separate layer for better caching.
COPY hop/hop.csproj hop/
RUN dotnet restore hop/hop.csproj

# Copy the rest of the source and publish a Release build.
COPY . .
RUN dotnet publish hop/hop.csproj -c Release -o out

# Runtime stage: stable .NET 10 ASP.NET runtime
FROM mcr.microsoft.com/dotnet/aspnet:10.0 AS hopruntime

WORKDIR /app
COPY --from=hopbuild /app/out ./

# .NET container images listen on 8080 by default.
EXPOSE 8080

ENTRYPOINT ["dotnet", "hop.dll"]