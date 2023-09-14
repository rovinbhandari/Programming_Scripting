using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Mvc;

namespace hop;

[Route("cameraangles")]
[ApiController]
[EnableCors("whop frontend")]
public class CameraController : Controller
{
    [HttpGet]
    public IActionResult GetCameraAngles()
    {
        var random = new Random(Seed: DateTime.Now.Millisecond);
        Func<double> randomVal = () => random.NextDouble() / 100.0d;
        var angles = new[]
        {
            new { X = randomVal(), Y = randomVal(), Z = randomVal() },
        };

        // TODO: Move to middleware
        HttpContext.Response.Headers.Append("Access-Control-Allow-Origin", "http://localhost:5173");
        HttpContext.Response.Headers.Append("Access-Control-Allow-Methods", "GET");
        return Ok(angles);
    }

    [HttpOptions]
    [HttpHead]
    public IActionResult GetCameraAnglesOptions()
    {
        HttpContext.Response.Headers.Append("Access-Control-Allow-Origin", "http://localhost:5173");
        HttpContext.Response.Headers.Append("Access-Control-Allow-Methods", "GET");
        return Ok();
    }
}
