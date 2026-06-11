using Scalar.AspNetCore;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring OpenAPI at https://aka.ms/aspnet/openapi
builder.Services.AddOpenApi();

// TODO: get ports through env variables or config
builder.Services.AddCors(builder => builder.AddPolicy("whop frontend", builder => { builder.WithOrigins("http://localhost:5173", "http://localhost:8080", "http://localhost:21248").AllowAnyHeader().WithMethods("GET", "OPTIONS", "HEAD"); })); // TODO: policy can be tightened.
builder.Services.AddControllers();
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
