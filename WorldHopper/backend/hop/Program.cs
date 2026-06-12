using System.Text.Json;
using System.Text.Json.Serialization;
using hop;
using Scalar.AspNetCore;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring OpenAPI at https://aka.ms/aspnet/openapi
builder.Services.AddOpenApi();

// Browser origins allowed to call the API (the Vite frontend).
// Configure via WorldHopper:AllowedOrigins (comma-separated) or env WorldHopper__AllowedOrigins.
var allowedOrigins = (builder.Configuration["WorldHopper:AllowedOrigins"] ?? "http://localhost:5173")
    .Split(',', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
builder.Services.AddCors(options => options.AddPolicy("whop frontend", policy =>
    policy.WithOrigins(allowedOrigins).AllowAnyHeader().WithMethods("GET")));
builder.Services.AddSingleton<CharacterDataService>();
builder.Services.AddControllers().AddJsonOptions(options =>
    options.JsonSerializerOptions.Converters.Add(new JsonStringEnumConverter(JsonNamingPolicy.CamelCase)));
var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.MapOpenApi();
    app.MapScalarApiReference();
}

app.UseCors("whop frontend");
app.MapControllers();
app.Run();
