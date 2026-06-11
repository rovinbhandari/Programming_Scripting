using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Mvc;

namespace hop;

[Route("characters")]
[ApiController]
[EnableCors("whop frontend")]
public class CharactersController : ControllerBase
{
    private readonly CharacterDataService _characters;

    public CharactersController(CharacterDataService characters)
    {
        _characters = characters;
    }

    // All travellers found in the data folder, each with its time-ordered hops.
    [HttpGet]
    public ActionResult<IReadOnlyList<Character>> GetCharacters() => Ok(_characters.GetCharacters());
}
