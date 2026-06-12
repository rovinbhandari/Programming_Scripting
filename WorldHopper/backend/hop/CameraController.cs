using Microsoft.AspNetCore.Mvc;

namespace hop;

[Route("cameraangles")]
[ApiController]
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

        return Ok(angles);
    }
}
