var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddCors(builder => builder.AddPolicy("whop frontend", builder => { builder.WithOrigins("http://localhost:5173", "http://localhost:8080", "http://localhost:21248").AllowAnyHeader().WithMethods("GET", "OPTIONS", "HEAD"); })); // TODO: policy can be tightened.
builder.Services.AddControllers();
var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseCors("whop frontend");
app.MapControllers();
app.Run();
