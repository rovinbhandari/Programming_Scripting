using Microsoft.AspNetCore.Mvc;

namespace hop;

[Route("cities")]
[ApiController]
public class CitiesController : Controller
{
    public CitiesController(/* TODO: need a singleton state for keeping track of cities */)
    {
    }

    [HttpGet]
    [Route("next")]
    public IActionResult GetNextCity()
    {
        // TODO: need to obtain data and map to coordinates before serving results.
        return Ok();
    }
}
